void read_callback(int fd, string str);
void close_callback(int fd);
void test() {
int s;
int res;
s = socket_create(2, "read_callback", "close_callback");
if (find_player("exash")) tell_object(find_player("exash"), "Create "+s+"\n");
res = socket_bind(s, 7087);
if (find_player("exash")) tell_object(find_player("exash"), "Bind "+res+"\n");
}

void read_callback(int fd, string str) {
if (find_player("exash")) tell_object(find_player("exash"), "Incoming "+str+"\n");
socket_close(fd);
}
void close_callback(int fd) {
if (find_player("exash")) tell_object(find_player("exash"), "Closing socket\n");
socket_close(fd);
}

