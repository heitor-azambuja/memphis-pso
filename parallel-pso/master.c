#include <api.h>  // Memphis parallel platform api
#include <stdlib.h>


void main() {
    Message msg;

    msg.lenght = 4;
    
    //  Send message containing rng seed to slaves
    msg.msg[0] = 135430;
    Send(&msg, slave01);
    Echo("Sent seed to slave 01");

    msg.msg[0] = 1;
    Send(&msg, slave02);
    Echo("Sent seed to slave 02");

    msg.msg[0] = 78951;
    Send(&msg, slave03);
    Echo("Sent seed to slave 03");

    msg.msg[0] = 98512;
    Send(&msg, slave04);
    Echo("Sent message to slave 04");


    // Receive message from slaves
    Receive(&msg, slave01);
    Echo("Received message from slave 01");
    Echo("Slave 01 best fitness: ");
    Echo(itoa(msg.msg[0]));
    Echo("Slave 01 best position: ");
    Echo(itoa(msg.msg[1]));
    Echo(itoa(msg.msg[2]));
    Echo(itoa(msg.msg[3]));
    
    Receive(&msg, slave02);
    Echo("Received message from slave 02");
    Echo("Slave 02 best fitness: ");
    Echo(itoa(msg.msg[0]));
    Echo("Slave 02 best position: ");
    Echo(itoa(msg.msg[1]));
    Echo(itoa(msg.msg[2]));
    Echo(itoa(msg.msg[3]));

    Receive(&msg, slave03);
    Echo("Received message from slave 03");
    Echo("Slave 03 best fitness: ");
    Echo(itoa(msg.msg[0]));
    Echo("Slave 03 best position: ");
    Echo(itoa(msg.msg[1]));
    Echo(itoa(msg.msg[2]));
    Echo(itoa(msg.msg[3]));

    Receive(&msg, slave04);
    Echo("Received message from slave 04");
    Echo("Slave 04 best fitness: ");
    Echo(itoa(msg.msg[0]));
    Echo("Slave 04 best position: ");
    Echo(itoa(msg.msg[1]));
    Echo(itoa(msg.msg[2]));
    Echo(itoa(msg.msg[3]));

    exit();

}