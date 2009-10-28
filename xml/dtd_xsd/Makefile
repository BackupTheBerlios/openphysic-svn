file=formation

all:
	$(MAKE) valid-dtd
	$(MAKE) valid-xsd

valid-dtd:
	xmllint --noout --loaddtd --valid ${file}.xml
	
valid-xsd:
	xmllint --noout ${file}.xml --schema ${file}.xsd