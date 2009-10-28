file=formation

all:
	$(MAKE) valid-dtd
	$(MAKE) valid-xsd

# DTD
valid-dtd:
	xmllint --noout --loaddtd --valid ${file}.xml

# XML Schema
valid-xsd:
	xmllint --noout ${file}.xml --schema ${file}.xsd
	
# RelaxNG
valid-rng:
	xmllint --relaxng ${file}.rng ${file}.xml