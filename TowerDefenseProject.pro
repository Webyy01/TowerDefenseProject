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
        gamecontroller.cpp \
        infernotower.cpp \
        main.cpp \
        map.cpp \
        shop.cpp \
        teslatower.cpp \
        tower.cpp \
        utility.cpp \
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
    gamecontroller.h \
    map.h \
    shop.h \
    tower.h \
    utility.h

RESOURCES += \
    Images.qrc
