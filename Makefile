build:
	gcc *.c -o lanParty -g
clean:
	rm -f lanParty
run:
	./lanParty c.in d.in r.out