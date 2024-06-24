CC = gcc
CFLAGS = -Wall -g
TARGETS = cal cat cjliaoOSshell cp date ls mkdir mv ps pwd rm rmdir top vi whoami

all: $(TARGETS)

cal: cal.c
	$(CC) $(CFLAGS) -o cal cal.c

cat: cat.c
	$(CC) $(CFLAGS) -o cat cat.c

cjliaoOSshell: cjliaoOSshell.c
	$(CC) $(CFLAGS) -o cjliaoOSshell cjliaoOSshell.c

cp: cp.c
	$(CC) $(CFLAGS) -o cp cp.c

date: date.c
	$(CC) $(CFLAGS) -o date date.c

ls: ls.c
	$(CC) $(CFLAGS) -o ls ls.c

mkdir: mkdir.c
	$(CC) $(CFLAGS) -o mkdir mkdir.c

mv: mv.c
	$(CC) $(CFLAGS) -o mv mv.c

ps: ps.c
	$(CC) $(CFLAGS) -o ps ps.c

pwd: pwd.c
	$(CC) $(CFLAGS) -o pwd pwd.c

rm: rm.c
	$(CC) $(CFLAGS) -o rm rm.c

rmdir: rmdir.c
	$(CC) $(CFLAGS) -o rmdir rmdir.c

top: top.c
	$(CC) $(CFLAGS) -o top top.c

vi: vi.c
	$(CC) $(CFLAGS) -o vi vi.c

whoami: whoami.c
	$(CC) $(CFLAGS) -o whoami whoami.c

clean:
	rm -f $(TARGETS)
	rm -f history
