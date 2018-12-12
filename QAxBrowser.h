#ifndef QAXBROWSER_H
#define QAXBROWSER_H

#include <QWidget>
#include <QString>
#include <QDebug>
#include "oaidl.h"
namespace Ui {
class QAxBrowser;
}

class QAxBrowser : public QWidget
{

    Q_OBJECT
public:
    explicit QAxBrowser(QWidget *parent = 0);
    ~QAxBrowser();

    // 导航
    void navigate(QString const& address);

    // 历史记录中的上一个
    void goBack();

    // 历史记录中的下一个
    void goForward();

    // 主页/开始页
    void goHome();

    // 当前页
    void goSearch();

    // 停止
    void stop();

    // 刷新
    void refresh();

    // 设置是否屏蔽所有警告
    void setSlient(bool slient);

    // 设置属性
    void putProperty(QString const& property, QString const& value);


private slots:
    /*微软 ie 文档
     * https://docs.microsoft.com/en-us/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa752084(v=vs.85)
        */
    void on_axWidget_NavigateComplete(const QString &URL);
    void on_axWidget_ProgressChange(int Progress, int ProgressMax);
    void on_axWidget_DownloadBegin();
    void on_axWidget_DownloadComplete();
    void on_axWidget_OnQuit();
    void on_axWidget_BeforeNavigate(const QString &URL, int Flags, const QString &TargetFrameName, QVariant &PostData, const QString &Headers, bool &Cancel);
    void on_axWidget_CommandStateChange(int Command, bool Enable);
    void on_axWidget_DocumentComplete(IDispatch *pDisp, QVariant &URL);
    void on_axWidget_NavigateError(IDispatch *pDisp, QVariant &URL, QVariant &Frame, QVariant &StatusCode, bool &Cancel);
    void on_axWidget_NewProcess(int lCauseFlag, IDispatch *pWB2, bool &Cancel);
    void on_axWidget_NewWindow(const QString &URL, int Flags, const QString &TargetFrameName, QVariant &PostData, const QString &Headers, bool &Processed);
    void on_axWidget_OnFullScreen(bool FullScreen);
    void on_axWidget_OnVisible(bool Visible);
    void on_axWidget_PrintTemplateInstantiation(IDispatch *pDisp);
    void on_axWidget_PrintTemplateTeardown(IDispatch *pDisp);
    void on_axWidget_PropertyChange(const QString &szProperty);
    void on_axWidget_StatusTextChange(const QString &Text);
    void on_axWidget_TitleChange(const QString &Text);
    void on_axWidget_windowTitleChanged(const QString &title);

signals:
    void navigateComplete(const QString &URL);
    void progressChange(int Progress, int ProgressMax);
    void downloadBegin();
    void downloadComplete();
    void onQuit();
    void beforeNavigate(const QString &URL, int Flags, const QString &TargetFrameName, QVariant &PostData, const QString &Headers, bool &Cancel);
    void commandStateChange(int Command, bool Enable);
    void documentComplete(IDispatch *pDisp, QVariant &URL);
    void navigateError(IDispatch *pDisp, QVariant &URL, QVariant &Frame, QVariant &StatusCode, bool &Cancel);
    void newProcess(int lCauseFlag, IDispatch *pWB2, bool &Cancel);
    void newWindow(const QString &URL, int Flags, const QString &TargetFrameName, QVariant &PostData, const QString &Headers, bool &Processed);
    void onFullScreen(bool FullScreen);
    void onVisible(bool Visible);
    void printTemplateInstantiation(IDispatch *pDisp);
    void printTemplateTeardown(IDispatch *pDisp);
    void propertyChange(const QString &szProperty);
    void statusTextChange(const QString &Text);
    void titleChange(const QString &Text);
    void windowTitleChanged(const QString &title);

private:
    Ui::QAxBrowser *ui;
};

#endif // QAXBROWSER_H
