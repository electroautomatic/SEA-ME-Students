#include <QCoreApplication>
#include <QString>
#include <QTextStream>

QString convertToUpper(const QString& input) {
    return input.toUpper();
}

QString convertToLower(const QString& input) {
    return input.toLower();
}

QString processString(const QString& command, const QString& input) {
    QString result = input;

    if (command == "up") {
        result = convertToUpper(result);
    } else if (command == "down") {
        result = convertToLower(result);
    } else {

        return QString("Error: Invalid command. Use 'up' or 'down'.");
    }

    return result;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QTextStream out(stdout);

    if (argc != 3) {
        out << "Usage: " << argv[0] << " {command} {string}" << Qt::endl;
        out << "Commands: up, down" << Qt::endl;
        return 1;
    }

    QString command = argv[1];
    QString input = argv[2];

    QString result = processString(command, input);

    out << result << Qt::endl;

    return 0;
}
