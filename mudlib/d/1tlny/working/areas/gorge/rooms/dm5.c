#include <std.h>

inherit "std/room";

void create() {
     ::create();
     set_property("indoors", 1);
     set_property("light", 1);
set("short", "Entrance to maze"); 
set( "long",
    "The heat from this area is becoming unbearable.  It is seemingly
coming in waves. There are two huge pillars standing on both sides of a set
of roughly cut stairs going down.  There is a sign attached to one of the
pillars.\n"  
        );
    add_item( "sign", "Try reading it.\n",
    );
     add_item("pillars", " These two gothic pillars are seemely cut right out of the wall.  They are in the shape of two demons each holding an orb of some type.\n");
     add_item("stairs", "The stairs are rough-cut going down in a spiral.  They have been smoothed over by the immense heat coming from the bottom.\n");

     set_smell("default", "The heat is starting to burn your skin.\n");

     add_exit("dm3", "north");
     add_exit("dm7", "down");
}

void init()
{
     ::init();
add_action( "read", "read" );
}
   
int read()
{
    write(      "******************************" );
    write(      "**  FOOLISH MORTALS BEWARE  **" );
    write(      "**                          **" );
    write(      "**      HE WHO ENTERS THIS  **" );
    write(      "**                          **" );
    write(      "**                          **" );
    write(      "**        DEMON GORGE       **" );
    write(      "**                          **" );
    write(      "**                          **" );
    write(      "**                          **" );
    write(      "**      WILL SURELY DIE     **" );
    write(      "******************************" );
    write(      "******************************" );
return 1;
}
