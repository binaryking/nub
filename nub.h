/* Copyright 2013 Mohammed Nafees. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY MOHAMMED NAFEES ''AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO
 * EVENT SHALL EELI REILIN OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * The views and conclusions contained in the software and documentation
 * are those of the authors and should not be interpreted as representing
 * official policies, either expressed or implied, of Mohammed Nafees.
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

// Qt
#include <QWidget>
#include <QNetworkAccessManager>
#include <QUrl>
#ifdef Q_OS_MAC
#include "mac/MacWebView.h"
#else
#include <QWebView>
#endif

namespace Ui {
class MainWindow;
}

class O1Dropbox;
class O1RequestParameter;
class QByteArray;

class nub : public QWidget
{
    Q_OBJECT
public:
    explicit nub( QWidget *parent = 0 );
    ~nub();

private slots:
    void onLinkingFailed();
    void onLinkingSucceeded();
    void onOpenBrowser( QUrl url );
    void onCloseBrowser();
    void deauthorize();
    void authorize();
    void uploadFile( QString file );

private:
    Ui::MainWindow *ui;
    O1Dropbox *dropbox;
    QNetworkAccessManager *manager;
#ifdef Q_OS_MAC
    MacWebView *macWebView;
#else
    QWebView *qWebView;
#endif
};

#endif
