;;; Mon premier programme en Assembleur 80x86

	;; Segment des donn�es
	section .data
		msg db "Hello World",0xa	; cha�ne de caract�re
		len equ $-msg			; longueur de la cha�ne 

	;; Segment de code
	section .text

	global _start		; export du point d'entr�e du programme (loader)

	_start			; point d'entr�e du programme
		mov edx,len	; charge dans le registre �tendu la longueur de la cha�ne � afficher
		mov ecx,msg	; ecx pointeur de la cha�ne
		mov ebx,1	; ebx<=1 (stdout flux d'�criture)
		mov eax,4	; eax<=4 n� appel syst�me (sys write)
		int 0x80	; appel syst�me
		mov ebx,0	; code de retour
		mov eax,1	; numero de la fonction � appeler (1=sys-exit)
		int 0x80	; appel syst�me
	