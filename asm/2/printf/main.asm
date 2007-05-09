; -------------------------------------------------
; Programme C affichant le contenu d'une variable x
; -------------------------------------------------
;
;#include <stdio.h>
;int main( void )
;{
; unsigned int x =50;
; printf( "x=%i\n",x);
; return 0
;}

; -------------------------------------------------
; Programme assembleur �quivalent
; -------------------------------------------------
; 
; pour compiler cet exemple :
; $ nasm -f elf printf.asm
; $ gcc printf.o -o printf
; 
; Ex�cution :
; $ ./printf


extern printf	; fonction C externe, utilis�e par ce programme

;; Segment des donn�es
section .data
	msg:	db "x=%i",10,0	; chaine � passer � la fonction printf (doit se terminer par zero)
	x:	dd 50		; chaine 32 bits (double mot)

;; Segment de code
section .text

	
global main			; export du point d'entr�e du programme
main:				; point d'entr�e standard du C (ligne "int main(void)")
	; la fonction C print r�cup�re ses param�tres � partir
	; de la position m�moire point�e par ebp, dans la pile
	
	push	ebp		; sauvegarde de ebp
	mov	ebp, esp	; ebp pointe maintenant sur le haut de la pile
	push	dword [x]	; le contenu de la variable "x" est empil�
	push 	dword msg	; l'adresse de la chaine de caractere � afficher est empil�e
	call	printf		; appel de la fonction C printf
	add	esp, 8		; maintenant que printf est termin�e, nous devons restaurer
				; la pile � son �tat ant�rieur (on d�place le pointeur de la pile)

	pop	ebp		; restauration de ebp
	mov	eax, 0		; code de retour de la fonction main (ligne "return 0")
	ret			; sort de la fonction "main"
