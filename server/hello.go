package main

import (
	"fmt"
	"log"
	"code.google.com/p/go.net/websocket"
)

var origin = "http://localhost"
var url = "wss://secure.sakura.ad.jp/iot-alpha/ws/f549e005-48ba-4628-8bd7-9c3ba70ffb56"


func main(){
	fmt.Printf("setup ...¥n")
	ws, err := websocket.Dial(url, "",origin)
	if err != nil {
		log.Fatal(err);
	}

	message := []byte("hello world!")
	_, err = ws.Write(message)
	if err != nil {
		log.Fatal(err)
	}
	fmt.Pirntf("Send: %s¥n", message)

	var msg = make([]byte, 512)
	_, err = ws.Read(msg)
	if err != nil {
		log.Fatal(err)
	}
	fmt.Printf("Receive: %s¥n", msg)
	
	

}

