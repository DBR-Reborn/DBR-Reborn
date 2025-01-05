void do_it() {
seteuid(geteuid());
map_array(children("/std/obj/mon_corpse"), (:destruct:));
}
