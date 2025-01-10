inherit "/std/locker_room";

void create() {
   ::create();
   set_property("indoors",1);
   set_property("light",3);
  add_exit("/d/damned/guilds/voidwalker/skill_room", "south");
   set("short","The Voidwalker Treasury");
   set("long",
"This is the Voidwalker Treasury.  Any voidwalker may store items here, "
"but they are open to use by any other voidwalker.  Several lockers lie about.  \nMAKE SURE you close a locker after using it, "
"or the items may be lost!");
}

void reset(){
    object h_glyph;
    object locker;
    ::reset();
if (!present("regenerative glyph")) {
    h_glyph = new ("/std/glen/glyphs/h_glyph");
    h_glyph->move(this_object());
    }
}
