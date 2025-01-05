inherit "std/room";

string *demons = ({
  "/std/glen/pet/small_demon",
  "/std/glen/pet/normal_demon",
  "/std/glen/pet/greater_demon",
  "/std/glen/pet/lord_demon",
  "/std/glen/pet/prince_demon"});

void reset() {
    int i, k;
    object ob;
    ::reset();
    k = random(7) + random(7) + random(7);
    if(!present("demon"))
	for(i = 0; i < k; i++){
	    ob = new(demons[random(5)]);
	    ob->set_up(random(300));
	    ob->move(this_object());
	    ob->set_aggr_status(random(2));
	    ob->materialize();
	}

}
void create() {
    ::create();
    set_property("light",3);
    set_property("night light", 2);
    set_short("The Demon Plane");
    set_long("This is an outer realm of the demon plane.  "+
      "It is very hard to understand this place.  "+
      "Movement is difficult, the gravity and terrain "+
      "are very different here.  Demons can be seen "+
      "and heard in nearly every direction.  ");
}

