#include <api.h>  // Memphis parallel platform api
#include <stdlib.h>


void main() {
    Message msg;

    msg.length = 5;
    
    //  Send message containing pso parameters to slaves
    msg.msg[0] = 135430;  //  rng seed
    msg.msg[1] = 0;  //  lower bounds
    msg.msg[2] = 49;  //  upper bounds
    msg.msg[3] = 25;  //  population
    Send(&msg, slave01);
    Echo("Sent parameters to slave 01");

    msg.msg[0] = 1; //  rng seed
    msg.msg[1] = 50;  //  lower bounds
    msg.msg[2] = 99;  //  upper bounds
    Send(&msg, slave02);
    Echo("Sent parameters to slave 02");

    msg.msg[0] = 78951;
    msg.msg[1] = 100;
    msg.msg[2] = 149;
    Send(&msg, slave03);
    Echo("Sent parameters to slave 03");

    msg.msg[0] = 98512;
    msg.msg[1] = 150;
    msg.msg[2] = 200;
    Send(&msg, slave04);
    Echo("Sent parameters to slave 04");


    // Receive message from slaves
    Receive(&msg, slave01);
    Echo("Received results from slave 01");
    Echo("Slave 01 fitness: ");
    Echo(itoa(msg.msg[0]));
    // Echo("Slave 01 position: ");
    // Echo(itoa(msg.msg[1]));
    // Echo(itoa(msg.msg[2]));
    // Echo(itoa(msg.msg[3]));
    
    int best_fitness = msg.msg[0];
    int best_slave_idx = 1;
    
    Receive(&msg, slave02);
    Echo("Received results from slave 02");
    Echo("Slave 02 fitness: ");
    Echo(itoa(msg.msg[0]));
    // Echo("Slave 02 position: ");
    // Echo(itoa(msg.msg[1]));
    // Echo(itoa(msg.msg[2]));
    // Echo(itoa(msg.msg[3]));

    if (msg.msg[0] < best_fitness) {
        best_fitness = msg.msg[0];
        best_slave_idx = 2;
    }

    Receive(&msg, slave03);
    Echo("Received results from slave 03");
    Echo("Slave 03 fitness: ");
    Echo(itoa(msg.msg[0]));
    // Echo("Slave 03 position: ");
    // Echo(itoa(msg.msg[1]));
    // Echo(itoa(msg.msg[2]));
    // Echo(itoa(msg.msg[3]));

    if (msg.msg[0] < best_fitness) {
        best_fitness = msg.msg[0];
        best_slave_idx = 3;
    }

    Receive(&msg, slave04);
    Echo("Received results from slave 04");
    Echo("Slave 04 fitness: ");
    Echo(itoa(msg.msg[0]));
    // Echo("Slave 04 best position: ");
    // Echo(itoa(msg.msg[1]));
    // Echo(itoa(msg.msg[2]));
    // Echo(itoa(msg.msg[3]));

    if (msg.msg[0] < best_fitness) {
        best_fitness = msg.msg[0];
        best_slave_idx = 4;
    }

    Echo("Best fitness found: ");
    Echo(itoa(best_fitness));
    Echo("Best slave: ");
    Echo(itoa(best_slave_idx));

    exit();
}
