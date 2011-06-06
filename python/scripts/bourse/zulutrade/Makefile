#PYTHON=python
PYTHON=python3 # because of euro symbol

all:
	#$(MAKE) MyHistory
	$(PYTHON) ZuluTradeMyHistory.py > out.txt
	less out.txt

.PHONY: clean

MyHistory:
	$(PYTHON) ZuluTradeMyHistory.py
	
clean:
	$(RM) out.txt