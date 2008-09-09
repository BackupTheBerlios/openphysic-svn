var direction = true; // true=bas false=haut
var scroll = true;

function pageScroll() {
  scrolldelay = setTimeout('pageScroll()',100); // scrolls every 1000 milliseconds
  if (scroll) {
    if (bottom())
      direction=false;

    if (top())
      direction=true;

    if (direction) {
      window.scrollBy(0,10);
    } else {
      window.scrollBy(0,-10);    
    }
  }
}

function bottom()
{
  if ((document.body.scrollTop + document.body.clientHeight) == document.body.scrollHeight) {
    return true;
  } else {
    return false;
  }
}

function top()
{
  if ( document.body.scrollTop==0 ) {
    return true;
  } else {
    return false;
  }
}

