#include "QAxBrowser.h"
#include "ui_QAxBrowser.h"
#include <ActiveQt/QAxWidget>
#include <ActiveQt/QAxBase>
#include <iostream>

QAxBrowser::QAxBrowser(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QAxBrowser)
{
    ui->setupUi(this);
}

void QAxBrowser::navigate(QString const& address)
{
    ui->axWidget->dynamicCall("Navigate(const QString&)", address);
}

void QAxBrowser::goBack()
{
    ui->axWidget->dynamicCall("GoBack()");
}

void QAxBrowser::goForward()
{
    ui->axWidget->dynamicCall("GoForward()");
}

void QAxBrowser::goHome()
{
    ui->axWidget->dynamicCall("GoHome()");
}

void QAxBrowser::goSearch()
{
    ui->axWidget->dynamicCall("GoSearch()");
}

void QAxBrowser::stop()
{
     ui->axWidget->dynamicCall("Stop()");
}

void QAxBrowser::refresh()
{
     ui->axWidget->dynamicCall("Refresh()");
}

void QAxBrowser::setSlient(bool slient)
{
    if(slient)
        ui->axWidget->setProperty("Silent", "true");
    else
        ui->axWidget->setProperty("Silent", "false");
}

QAxBrowser::~QAxBrowser()
{
    delete ui;
}

void QAxBrowser::on_axWidget_NavigateComplete(const QString &URL)
{
    emit navigateComplete(URL);
}

void QAxBrowser::on_axWidget_OnQuit()
{
    emit quit();
}

void QAxBrowser::on_axWidget_ProgressChange(int Progress, int ProgressMax)
{
    emit progressChange(Progress, ProgressMax);
}

void QAxBrowser::on_axWidget_DownloadBegin()
{
    emit downloadBegin();
}

void QAxBrowser::on_axWidget_DownloadComplete()
{
    emit downloadComplete();
}
