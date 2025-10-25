#ifndef ADDAPPLICATION_H
#define ADDAPPLICATION_H

#include <QDialog>

namespace Ui {
class AddApplication;
}

class AddApplication : public QDialog {
    Q_OBJECT

public:
    explicit AddApplication(QWidget *parent = nullptr);
    ~AddApplication();

    QString company() const;
    QString position() const;
    QString status() const;
    QString dateApplied() const;
    QString notes() const;

private:
    Ui::AddApplication *ui;
};


#endif // ADDAPPLICATION_H
