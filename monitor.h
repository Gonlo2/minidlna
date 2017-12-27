int monitor_insert_file(const char *name, const char *path);
int monitor_insert_directory(int fd, char *name, const char * path);
int monitor_remove_file(const char * path);
int monitor_remove_directory(int fd, const char * path);

#if defined(HAVE_INOTIFY) || defined(HAVE_KQUEUE)
#define	HAVE_WATCH 1
int	add_watch(const char *);
#endif

#ifdef HAVE_INOTIFY
struct remote_inotify {
    uint32_t mask;
    uint32_t cookie;
    char *id;
    char *name;
    char *path;
};

void *
start_remote_inotify();

int
parse_inotify_event(char *buffer, int size, struct remote_inotify *event);

uint32_t crc32(char *data, int size);
#endif
