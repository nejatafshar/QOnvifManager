#include "user.h"
#include "message.h"

using namespace ONVIF;

Users::Users(QObject* parent) : QObject(parent) {}
Users::~Users() {}

QDomElement
Users::toxml(QString mainTag) {
    QDomElement setUsers;
    setUsers = newElement(mainTag);
    setUsers.setAttribute("xmlns", "http://www.onvif.org/ver10/device/wsdl");
    for (int i = 0; i < m_userNames.length(); i++) {
        QDomElement user = newElement("User");
        QDomElement username = newElement("Username", m_userNames[i]);
        username.setAttribute("xmlns", "http://www.onvif.org/ver10/schema");
        QDomElement password = newElement("Password", m_passWords[i]);
        password.setAttribute("xmlns", "http://www.onvif.org/ver10/schema");
        QDomElement level = newElement("Port", m_userLevel[i]);
        level.setAttribute("xmlns", "http://www.onvif.org/ver10/schema");

        user.appendChild(username);
        user.appendChild(password);
        user.appendChild(level);
        setUsers.appendChild(user);
    }
    return setUsers;
}




