<?php
	$fpdf->AddPage();
	$fpdf->SetFont('Arial','B',16);
	$fpdf->Cell(40,10,$data);
	echo $fpdf->fpdfOutput();	
?>