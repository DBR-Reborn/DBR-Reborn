inherit "/std/Object";

void create() {
  ::create();
  set_id( ({ "quill", "magic quill", "magical quill" }) );
  set_name("quill");
  set_short("A magical quill");
  set_long("This quill has a tip of everlasting ink, and a special feather that allows the writer to erase things with it. The problem is, it will not print on normal paper - only on specially prepared earth.");
  set_weight(5);
  set_value(30);
  return;
}
