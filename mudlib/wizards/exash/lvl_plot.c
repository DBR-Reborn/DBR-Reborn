void do_plot() {
int i;
for (i = 51; i < 202; i+=5) {
if (find_player("exash")) tell_object(find_player("exash"), "Running with "+i+"\n");
write_file("/wizards/exash/level_plot", ""+i+": "+("/adm/daemon/advance_d"->get_exp(i)-"/adm/daemon/advance_d"->get_exp(i-1))+"\n");
}
}
