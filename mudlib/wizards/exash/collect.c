void do_it() {
string key;
mapping muds;
muds = "/wizards/exash/network"->get_all();
foreach(key in keys(muds)) {
write_file("/wizards/exash/mudfile", muds[key]["HOSTADDRESS"]+":"+muds[key]["PORT"]+"\n");
}
}
