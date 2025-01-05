mapping mem_diag() {
mapping objs;
object ob;
objs = ([]);
foreach (ob in objects()) {
if (member_array(base_name(ob), keys(objs)) >= 0) {
objs[base_name(ob)]++;
}else {
objs[base_name(ob)] = 1;
}
}
return objs;
}

int test() {return sizeof(objects()); }
mapping get_objcount() {
mapping objnums, objs;
int ind;
string str;
objnums = ([]);
objs = mem_diag();
foreach (str in keys(objs)) {
ind = objs[str];
if (member_array(ind, keys(objnums)) >= 0) {
objnums[ind] = objnums[ind]+({str});
}else {
objnums[ind] = ({str});
}
}
return objnums;
}

mapping get_max20() {
mapping m, maxes;
int i;
m = get_objcount();
maxes = ([]);
for (i = 0; i < 20; i++) {
maxes[max(keys(m))] = m[max(keys(m))][0];
map_delete(m, max(keys(m)));
}
return maxes;
}
