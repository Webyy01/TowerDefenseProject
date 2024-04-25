QT += core widgets multimedia

CONFIG += c++17 cmdline
QT+= widgets
QT += gui
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        bullet.cpp \
        cannontower.cpp \
        enemy.cpp \
        infernotower.cpp \
        main.cpp \
        map.cpp \
        player.cpp \
        shop.cpp \
        teslatower.cpp \
        tower.cpp \
        xbowtower.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    InfernoTower.h \
    TeslaTower.h \
    XbowTower.h \
    bullet.h \
    cannontower.h \
    enemy.h \
    map.h \
    player.h \
    shop.h \
    tower.h

RESOURCES += \
<<<<<<< HEAD
    images.qrc \
    sounds.qrc
=======
    images.qrc
>>>>>>> 0b9fd878905c278d6fc362e14a2f77b890f1bcd2
