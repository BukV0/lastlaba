#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTextEdit>
#include <QFontDialog>
#include <QPainter>
#include <QTextBlock>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setCentralWidget(ui->textEdit);
    //connect(ui->textEdit, SIGNAL(currentCharFormatChanged), this, SLOT(updateLineNumberAreaWidth));
    //connect(this, &CodeEditor::updateRequest, this, &CodeEditor::updateLineNumberArea);
    //connect(ui->textEdit,SIGNAL(cursorPositionChanged()),this,SLOT(highlightCurrentLine()));
    highlightCurrentLine();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionCancel_triggered()
{
    ui->textEdit->undo();
}

void MainWindow::on_actionclose_triggered()
{
    emit exit(0);
}

void MainWindow::on_actionRepeat_triggered()
{
    ui->textEdit->redo();
}

void MainWindow::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}

void MainWindow::on_actionCut_triggered()
{
    ui->textEdit->cut();
}

void MainWindow::on_actionPast_triggered()
{
    ui->textEdit->paste();
}

void MainWindow::on_actionSelect_All_triggered()
{
    ui->textEdit->selectAll();
}

void MainWindow::on_actionWord_wrap_toggled(bool arg1)
{
    if(arg1){
        ui->textEdit->setLineWrapMode(QTextEdit::WidgetWidth);
    }
    else{
        ui->textEdit->setLineWrapMode(QTextEdit::NoWrap);
    }
}

void MainWindow::on_actionfont_triggered()
{
    bool b0k;
    QFont fnt = QFontDialog::getFont(&b0k,this);
    if(b0k) {
    ui->textEdit->setFont(fnt);
    }
}
void MainWindow::highlightCurrentLine()
{
    QList<QTextEdit::ExtraSelection> extraSelections;

    if (!ui->textEdit->isReadOnly()) {
        QTextEdit::ExtraSelection selection;

        QColor lineColor = QColor(Qt::blue).lighter(160);

        selection.format.setBackground(lineColor);
        selection.format.setProperty(QTextFormat::FullWidthSelection, true);
        selection.cursor = ui->textEdit->textCursor();
        selection.cursor.clearSelection();
        extraSelections.append(selection);
    }

    ui->textEdit->setExtraSelections(extraSelections);
}
