inherit "/std/armour";

void create() {
    ::create();
    set_name("flamespitter");
    set("id", ({ "spitter", "flamespitter" }) );
    set("short", "Flamespitter");
    set("long",
      "This peculiar object looks vaguely like a halloween mask of a sickly\n"
      +"mosquitto.  The inner surface is covered with small waving tenticles,\n"
      +"probably used to hold the mask to the face of the Tergoyle.  This mask\n"
      +"apparently lets a Tergoyle breath fire, though you can't discover the\n"
      +"mechanism yourself.\n");
    set_weight(30);
    set_value(100);
    set_type("metal head");
    set_limbs( ({ "head" }) );
    set_ac(5);
    set_ac(25,"fire");
    set_material("/misc/chitin");
    set_wear(
      "The Flamespitter molds itself to your face with a liquid sucking sound.\n"
      +"You gasp for breath as a fleshy tube extends down your throat, but\n"
      +"breathe more easily as slender tenticles work their way up your nose\n"
      +"and begin to emit a sweet smelling gas.\n");
    set_remove(
      "You strugle to tear the Flamespitter from your face and gasp and choke\n"
      +"as it withdraws its tenticles from your mouth and nose.\n");
}
