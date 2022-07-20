#ifndef IO_H
#define IO_H

	unsigned char portByteIn(unsigned char port);
	void portByteOut(unsigned char port,unsigned char data);
	unsigned short portWordIn(unsigned short port);
	void portWordOut(unsigned short port,unsigned short data);

#endif