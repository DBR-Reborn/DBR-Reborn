inherit "/std/armour";
void create() {
  ::create();
   set_name("shorts");
   set("id", ({ "shorts", "green shorts" }) );
   set("short", "A pair of green shorts");
   set("long", @SHORTS
A small pair of green shorts, it belonged to a toddler.  They are
small and do not protect the body well.
SHORTS
   );
   set_weight(30);
   set_value(2);
   set_type("cloth legs");
   set_limbs( ({ "right leg", "left leg" }) );
   set_ac(4);
   set_material("misc/cloth");
}
