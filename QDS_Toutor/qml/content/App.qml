// Copyright (C) 2021 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR GPL-3.0-only

import QtQuick 6.5
import QtQuick.Controls 6.5
//import UntitledProject

Window {
    width: 500
    height: 200
    id:root
    visible: true
    title: "UntitledProject"

    Button {
        id: button
        x: 413
        y: 16
        width: 63
        height: 33
        text: qsTr("Close")
        onClicked: {
        root.close()
        }
    }

    Button {
        id: button1
        x: 43
        y: 108
        width: 67
        height: 28
        text: qsTr("写入参数")
        onClicked:{
        var string = textEdit.text
        connector.setValue(string)
        }
    }

    Button {
        id: button2
        x: 126
        y: 108
        width: 64
        height: 28
        text: qsTr("读取参数")

        onClicked:{

        var string = connector.getValue()
        text1.text = string
        }
    }

    Connections{
    target:connector
    onSig_updateValue: {
            text2.text = strMessage
            console.log("Received signal from C++ with index:", strMessage)
    }
    }


    Text {
        id: text1
        x: 126
        y: 76
        width: 64
        height: 15
        text: qsTr("Text")
        font.pixelSize: 12
    }

    TextEdit {
        id: textEdit
        x: 40
        y: 76
        width: 80
        height: 20
        text: qsTr("Text Edit")
        font.pixelSize: 12
    }
    
    Text {
        id: text2
        x: 267
        y: 69
        width: 100
        height: 15
        text: qsTr("来自后端")
        font.pixelSize: 12
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
    }



}

