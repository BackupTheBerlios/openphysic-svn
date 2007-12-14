REM Script de copie de fichiers depuis les comptes utilisateurs
REM Sebastien CELLES
REM 12/12/2007

Const dirOrigine = "\\Andromede\Comptes\GTE\dut"
Const dirDestination =  "C:\Documents and Settings\scelles\Mes documents\copie"
Const liste = "C:\Documents and Settings\scelles\Mes documents\liste.txt"
Const listeErr = "C:\Documents and Settings\scelles\Mes documents\listeErr.txt"
Const matiere = "autocad"
Const extension = "*.dw?" 


Const FOR_READING = 1
Const blnUNICODE = FALSE

Const OverWriteFiles = TRUE 

Dim objFSO, objTS, strContents

Set objFSO = CreateObject("Scripting.FileSystemObject") 

msgbox("Copie en cours")

REM Lecture du fichier liste des eleves -> classe (type Array)
REM classe = Array("pamyot","qantoine")
If objFSO.FileExists(liste) Then
  Set objTS = objFSO.OpenTextFile(liste, FOR_READING, False, blnUNICODE)
end if
strContents = objTS.ReadAll
objTS.Close
classe=Split(strContents, vbCrLf)


For Each eleve In classe
  REM msgbox("Copie des fichiers de "+eleve)
  REM WScript.Echo "Copie des fichiers de "+eleve
  
  REM Creation repertoire utilisateur (si le répertoire parent existe et que le répertoire à créer n'existe pas déjà)
  if ( objFSO.FolderExists(dirDestination)=true and objFSO.FolderExists(dirDestination+"\"+eleve)=false ) then
	objFSO.CreateFolder(dirDestination+"\"+eleve)
  end if
  
  REM Creation sous-repertoire utilisateur (si le répertoire parent existe et que le répertoire à créer n'existe pas déjà)
  if ( objFSO.FolderExists(dirDestination+"\"+eleve)=true and objFSO.FolderExists(dirDestination+"\"+eleve+"\"+matiere)=false ) then
	objFSO.CreateFolder(dirDestination+"\"+eleve+"\"+matiere)
  end if
  
  fromFile = dirOrigine+"\"+eleve+"\"+matiere+"\"+extension
  toFile = dirDestination+"\"+eleve+"\"+matiere
  
  REM WScript.Echo "Copie de "+vbCrLf+fromFile+vbCrLf+"vers "+vbCrLf+toFile
  
REM if objFSO.FileExists(fromFile)=true then
	On Error Resume Next
	objFSO.CopyFile fromFile, toFile, OverWriteFiles
REM else
REM	msgbox("Erreur de copie pour "+eleve)
REM end if

Next



msgbox("Fin de la copie de tous les fichiers")

REM ErreurCopie:
REM	msgbox("Erreur de copie)
