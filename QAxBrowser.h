﻿#ifndef QAXBROWSER_H
#define QAXBROWSER_H

#include <QWidget>
#include <QString>
#include <QDebug>

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
     * https://docs.microsoft.com/en-us/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa752084(v=vs.85)*/
    void on_axWidget_NavigateComplete(const QString &URL);
    void on_axWidget_ProgressChange(int Progress, int ProgressMax);
    void on_axWidget_DownloadBegin();
    void on_axWidget_DownloadComplete();
    void on_axWidget_OnQuit();

signals:
    void navigateComplete(const QString &URL);
    void progressChange(int Progress, int ProgressMax);
    void downloadBegin();
    void downloadComplete();
    void quit();

private:
    Ui::QAxBrowser *ui;
};

#endif // QAXBROWSER_H
