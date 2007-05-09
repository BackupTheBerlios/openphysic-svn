; ------------------------------------------------------------------------------
; Fonction qui passe en majuscule tous les caract�res d'une cha�ne de caract�res
; Technique :
; a = $41 = 0100 0001
; A = $61 = 0110 0001
; faire un OU avec
;         b 0010 0000 = d 32
; ------------------------------------------------------------------------------

extern printf	; fonction C externe, utilis�e par ce programme

;; Segment des donn�es
section .data
	msg_a		db "abcdiag",10,0	; chaine � passer � la fonction printf (doit se terminer par zero)
	msg_a_len	equ $ - msg_a - 2	;7 taille de la chainei
	msg_b		db "a",10,0
	msg_result	db "%i",0
	result		db "",10,0
;	occu		dd 0


;; Segment de code
section .texte

	
global main			; export du point d'entr�e du programme
main:				; point d'entr�e standard du C (ligne "int main(void)")
	; la fonction C print r�cup�re ses param�tres � partir
	; de la position m�moire point�e par ebp, dans la pile
	
	push	ebp		; sauvegarde de ebp
	mov	ebp, esp	; ebp pointe maintenant sur le haut de la pile

	mov	esi, msg_a
	mov	edi, result
	mov	ecx, msg_a_len
	mov	eax, 0
	mov	ebx, 0

boucle:
	lodsb
	cmp	esi, dword msg_b
	je	incremente
suite:
	cmp	ecx,0
	je	boucle_affich
	stosb
	loop	boucle

incremente:
	inc	ebx
	jmp	suite

boucle_affich:
	push	ebx
	push	msg_result
	call	printf

	mov	esp, ebp

	pop	ebp		; restauration de ebp
	mov	eax, 0		; code de retour de la fonction main (ligne "return 0")
	ret			; sort de la fonction "main"
