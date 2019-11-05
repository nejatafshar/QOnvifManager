#ifndef SYSTEMREBOOT_H
#define SYSTEMREBOOT_H
#include <QDomElement>
#include <QObject>
namespace ONVIF {
class SystemReboot : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool result READ result WRITE setResult)


public:
    explicit SystemReboot(QObject* parent = NULL);
    virtual ~SystemReboot();
    QDomElement toxml();
    bool        result() const {
        return m_result;
    }
public slots:
    void setResult(bool arg) {
        m_result = arg;
    }

private:
    bool m_result;
};
} // namespace ONVIF
#endif // SYSTEMREBOOT_H
