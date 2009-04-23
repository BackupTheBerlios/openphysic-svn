grammar THERMOSTAT;

scpi    :	HEAT STATE
	|	SET HEAT STATE
        |       GET HEAT
	|	SET TEMPERATURE NUMBER
	|       GET TEMPERATURE
	;

HEAT    :	'heat';
STATE	:	'on' | 'off';
TEMPERATURE	:	'temperature';
GET	:	'get';
SET	:	'set';
NUMBER	:	'0'..'9'+;
