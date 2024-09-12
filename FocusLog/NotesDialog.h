#ifndef NOTESDIALOG_H
#define NOTESDIALOG_H
#include <QDialog>

class NotesDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NotesDialog(QWidget *parent = nullptr);

private:
    //QLineEdit* notesInput;
    //DatabaseManager* dbManager;

private slots:
    void onSaveNotes();  // Слот для сохранения заметок
};
#endif // NOTESDIALOG_H
