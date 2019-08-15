#ifndef _LINUX_NLS_H
#define _LINUX_NLS_H

//#include <linux/init.h>

/* unicode character */
typedef __WCHAR_TYPE__ wchar_t;

struct nls_table {
	char *charset;
	int (*uni2char) (wchar_t uni, unsigned char *out, int boundlen);
	int (*char2uni) (const unsigned char *rawstring, int boundlen,
			 wchar_t *uni);
	unsigned char *charset2lower;
	unsigned char *charset2upper;
	struct module *owner;
	struct nls_table *next;
};

/* this value hold the maximum octet of charset */
#define NLS_MAX_CHARSET_SIZE 3

/* nls.c */
extern int register_nls(struct nls_table *);
extern int unregister_nls(struct nls_table *);
extern struct nls_table *load_nls(char *);
extern void unload_nls(struct nls_table *);
extern struct nls_table *load_nls_default(void);


#endif /* _LINUX_NLS_H */

