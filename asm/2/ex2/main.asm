; -------------------------------------------
; Programme affichant le maximum de 2 nombres
; -------------------------------------------

extern printf	; fonction C externe, utilis�e par ce programme

;; Segment des donn�es
section .data
	msg_x:	db "x=%i",10,0	; chaine � passer � la fonction printf (doit se terminer par zero)
	x:	dd 155		; chaine 32 bits (double mot)
	msg_y:	db "y=%i",10,0 	; 10=retour chariot 0=caract�re de fin de chaine
	y:	dd 61
	msg_z: db "max(x,y)=%i",10,0


;; Segment de code
section .text

	
global main			; export du point d'entr�e du programme
main:				; point d'entr�e standard du C (ligne "int main(void)")
	; la fonction C print r�cup�re ses param�tres � partir
	; de la position m�moire point�e par ebp, dans la pile
	
	push	ebp		; sauvegarde de ebp
	mov	ebp, esp	; ebp pointe maintenant sur le haut de la pile

	push	dword [x]	; le contenu de la variable "x" est empil�
	push 	dword msg_x	; l'adresse de la chaine de caractere � afficher est empil�e
	call 	printf		; appel de la fonction C printf

	push	dword [y]
	push	dword msg_y
	call	printf		; appel de la fonction C printf

	mov     eax,dword[x]
	mov	ebx,dword[y]
	cmp	eax,ebx
	JA	x_sup_y
	JB	y_sup_x

	x_sup_y:
		push 	dword[x]	
		push	dword msg_z
		call	printf
		jmp	fin

	y_sup_x:
		push	dword[y]
		push	dword msg_z	; affichage
		call	printf

	fin:

	mov	esp, ebp	; remet esp dans ebp

	pop	ebp		; restauration de ebp
	mov	eax, 0		; code de retour de la fonction main (ligne "return 0")
	ret			; sort de la fonction "main"
