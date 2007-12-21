// Traitement d'images numeriques
// Scilab + toolbox SIVP
// http://sivp.sourceforge.net/doc.php

clear

a=imread("lena.png");
imshow(a)


// Comparative study of Matlab and Scilab
// http://www.ossrc.org.in/downloads/comparative-study-of-Matlab-and-Scilab.pdf
//Averaging
// The same operation can be accomplished using the imaver function given in the appendix A
// written by srikanth
//  a=imread('d.jpg');
//   si=size(a);
//    for i=2:(si(1)-1)
//         for j=2:(si(2)-1)
//            c(i,j)=a(i,j)+a(i-1,j)+a(i+1,j)+a(i,j+1)+a(i-1,j+1)+a(i+1,j+1)+a(i,j-1)+a(i-1,j-1)+a(i+1,j-1);
//            c(i,j)=c(i,j)/9;
//         end
//    end
//  imshow(c);

//Slicing
// this operation of bit slicing can be performed on SCILAB using the im2bw function where the
// threshold value can be used to control the degree of darkness
//         im=gray_imread('d.jpg');
//         bwim=im2bw(im,0.4);
//         imshow(bwim);

