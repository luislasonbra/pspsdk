/*
 * PSP Software Development Kit - http://www.pspdev.org
 * -----------------------------------------------------------------------
 * Licensed under the BSD license, see LICENSE in PSPSDK root for details.
 *
 * string.h
 *
 * Copyright (c) 2002-2004 PS2DEV
 * Copyright (c) 2005 Marcus R. Brown <mrbrown@ocgnet.org>
 * Copyright (c) 2005 James Forshaw <tyranid@gmail.com>
 * Copyright (c) 2005 John Kelley <ps2dev@kelley.ca>
 *
 * $Id: string.h 1095 2005-09-27 21:02:16Z jim $
 */

#ifndef _STRING_H
#define _STRING_H

#include <stddef.h>
#include <stdarg.h>

#ifdef __cplusplus
extern "C" {
#endif


/* ASM String functions by Jeff Johnston of Cygnus Solutions */
void *	memchr(const void *, int, size_t);
void *	memcpy(void *, const void *, size_t);
void *	memmove(void *, const void *, size_t);
void *	memset(void *, int, size_t);

int	memcmp(const void *, const void *, size_t);

int	strcmp(const char *, const char *);
int	strncmp(const char *, const char *, size_t);

unsigned int strlen(const char *);

char *  strdup(const char *s);

char *	strcat(char *, const char *);
char *	strchr(const char *, int);
char *	strcpy(char *, const char *);
char *	strncat(char *, const char *, size_t);
char *	strncpy(char *, const char *, size_t);

char *  strpbrk(const char *s, const char *accept);
size_t  strspn(const char *s, const char *accept);
size_t  strcspn(const char *s, const char *reject);

static __inline__ int strcoll(const char *s1, const char *s2) { return strcmp(s1, s2); }
static __inline__ size_t strxfrm(char *dest, const char *src, size_t n) { strncpy(dest, src, n); return n; }

char *  strerror(int);

// copies ascii string to sjis string
// 
// args:    dest sjis string buffer
//          source ascii string buffer
// returns: length of ascii string copied
int strcpy_sjis(short* sjis_buff, const char* ascii_buff);

// copies sjis string to ascii string
// 
// args:    dest ascii string buffer
//          source sjis string buffer
// returns: length of sjis string copied
int strcpy_ascii(char* ascii_buff, const short* sjis_buff);


/* C String functions by Hiryu (A.Lee) */
#define stricmp strcasecmp
#define strnicmp strncasecmp

int	 strcasecmp(const char *, const char *);
int	 strncasecmp(const char *, const char *, size_t);

char *	strtok(char *, const char *);
char *	strrchr(const char *, int);

char *	strstr(const char *, const char *);

char * strupr(char *);
char * strlwr(char *);

static __inline__ void bzero(void * p, size_t n) { memset(p, 0, n); }
static __inline__ void bcopy(const void * s, void * d, size_t n) { memcpy(d, s, n); }
static __inline__ int bcmp(const void * s1, const void * s2, size_t n) { return memcmp(s1, s2, n); }
static __inline__ char * index(const char * s, int c) { return strchr(s, c); }
static __inline__ char * rindex(const char * s, int c) { return strrchr(s, c); }

/* Backward compatibility... */
#include <ctype.h>

#ifdef __cplusplus
}
#endif

#endif	// _STRING_H
