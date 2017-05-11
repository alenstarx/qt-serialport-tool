﻿#include "jvmessagebox.h"
#include "jvhelper.h"
#ifndef I18N
#define i18nConve(x) (x)
#else
#define i18nConve(x) QString::fromStdString(I18NRepo::getInstance()->Get(std::string("Other"), std::string(x)))
#endif

JVMessageBox::JVMessageBox(bool center, QWidget *parent) :
    QDialog(parent)
{
    this->setupUi();

    this->mousePressed = false;
    //设置窗体标题栏隐藏
    this->setWindowFlags(Qt::FramelessWindowHint);
    //设置窗体关闭时自动释放内存
    this->setAttribute(Qt::WA_DeleteOnClose);
    //设置图形字体
    JVHelper::GetInstance()->SetIcon(this->lab_Ico, QChar(0xf015), 12);
    JVHelper::GetInstance()->SetIcon(this->btnMenu_Close, QChar(0xf00d), 10);
    //关联关闭按钮
    connect(this->btnMenu_Close, SIGNAL(clicked()), this, SLOT(close()));
    connect(this->btnCancel, SIGNAL(clicked()), this, SLOT(close()));

    if(center){
        //窗体居中显示
        JVHelper::FormInCenter(this);
    }
    else {
        JVHelper::FormInMouse(this);
    }

    this->btnCancel->setText(i18nConve("&Cancel"));
    this->btnOk->setText(i18nConve("&OK"));
	this->lab_Ico->setPixmap(JVHelper::GetInstance()->GetAppIcon().pixmap(24, 24));
}

JVMessageBox::~JVMessageBox()
{
    //delete ui;
}

void JVMessageBox::SetMessage(const QString &msg, int type)
{
    if (type == 0) {
        this->labIcoMain->setStyleSheet("border-image: url(:/theme/info.png);");
        this->btnCancel->setVisible(false);
        this->lab_Title->setText(i18nConve("Info"));
        this->setWindowTitle(i18nConve("Info"));
    } else if (type == 1) {
        this->labIcoMain->setStyleSheet("border-image: url(:/theme/question.png);");
        this->lab_Title->setText(i18nConve("Question"));
        this->setWindowTitle(i18nConve("Question"));
    } else if (type == 2) {
        this->labIcoMain->setStyleSheet("border-image: url(:/theme/error.png);");
        this->btnCancel->setVisible(false);
        this->lab_Title->setText(i18nConve("Error"));
        this->setWindowTitle(i18nConve("Error"));
    }

    this->labInfo->setText(msg);
}

void JVMessageBox::on_btnOk_clicked()
{
    done(1);
    this->close();
}

void JVMessageBox::mouseMoveEvent(QMouseEvent *e)
{
    if (mousePressed && (e->buttons() && Qt::LeftButton)) {
        this->move(e->globalPos() - mousePoint);
        e->accept();
    }
}

void JVMessageBox::mousePressEvent(QMouseEvent *e)
{
    if (e->button() == Qt::LeftButton) {
        mousePressed = true;
        mousePoint = e->globalPos() - this->pos();
        e->accept();
    }
}

void JVMessageBox::mouseReleaseEvent(QMouseEvent *)
{
    mousePressed = false;
}

#undef I18N

