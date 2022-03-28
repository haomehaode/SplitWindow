#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_SplitWindow.h"


class SplitWindow : public QMainWindow
{
    Q_OBJECT

public:
    SplitWindow(QWidget *parent = Q_NULLPTR);

public slots:

    void slot_vertical_splitter();
    void slot_horizontal_splitter();
    void slot_delete_splitter();

    void  slot_add_label();

private:
    Ui::SplitWindowClass ui;
};
