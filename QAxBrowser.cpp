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

QVariant QAxBrowser::dynamicCall(const char *name, const QVariant &v1,
                                       const QVariant &v2,
                                       const QVariant &v3,
                                       const QVariant &v4,
                                       const QVariant &v5,
                                       const QVariant &v6,
                                       const QVariant &v7,
                                       const QVariant &v8)
{
   return ui->axWidget->dynamicCall(name, v1, v2, v3, v4, v5, v6, v7, v8);
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
    emit onQuit();
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

void QAxBrowser::on_axWidget_BeforeNavigate(const QString &URL, int Flags, const QString &TargetFrameName, QVariant &PostData, const QString &Headers, bool &Cancel)
{
    emit beforeNavigate(URL, Flags, TargetFrameName, PostData, Headers, Cancel);
}

void QAxBrowser::on_axWidget_CommandStateChange(int Command, bool Enable)
{
    emit commandStateChange(Command, Enable);
}

void QAxBrowser::on_axWidget_DocumentComplete(IDispatch *pDisp, QVariant &URL)
{
    emit documentComplete(pDisp, URL);
}

void QAxBrowser::on_axWidget_NavigateError(IDispatch *pDisp, QVariant &URL, QVariant &Frame, QVariant &StatusCode, bool &Cancel)
{
    emit navigateError(pDisp, URL, Frame, StatusCode, Cancel);
}

void QAxBrowser::on_axWidget_NewProcess(int lCauseFlag, IDispatch *pWB2, bool &Cancel)
{
    emit newProcess(lCauseFlag, pWB2, Cancel);
}

void QAxBrowser::on_axWidget_NewWindow(const QString &URL, int Flags, const QString &TargetFrameName, QVariant &PostData, const QString &Headers, bool &Processed)
{
    emit newWindow(URL, Flags, TargetFrameName, PostData, Headers, Processed);
}

void QAxBrowser::on_axWidget_OnFullScreen(bool FullScreen)
{
    emit onFullScreen(FullScreen);
}

void QAxBrowser::on_axWidget_OnVisible(bool Visible)
{
    emit onVisible(Visible);
}

void QAxBrowser::on_axWidget_PrintTemplateInstantiation(IDispatch *pDisp)
{
    emit printTemplateInstantiation(pDisp);
}

void QAxBrowser::on_axWidget_PrintTemplateTeardown(IDispatch *pDisp)
{
    emit printTemplateTeardown(pDisp);
}

void QAxBrowser::on_axWidget_PropertyChange(const QString &szProperty)
{
    emit propertyChange(szProperty);
}

void QAxBrowser::on_axWidget_StatusTextChange(const QString &Text)
{
    emit statusTextChange(Text);
}

void QAxBrowser::on_axWidget_TitleChange(const QString &Text)
{
    emit titleChange(Text);
}

void QAxBrowser::on_axWidget_windowTitleChanged(const QString &title)
{
    emit windowTitleChanged(title);
}
