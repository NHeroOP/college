/* portal.js - small JavaScript for the student portal. Design only: no login checks, no data. */

// Apply the saved theme straight away (same key as the public site) so there is no flash.
var savedTheme = null;
try { savedTheme = localStorage.getItem("gcet-theme"); } catch (e) {}
document.documentElement.setAttribute("data-theme",
  savedTheme || (window.matchMedia("(prefers-color-scheme: dark)").matches ? "dark" : "light"));

document.addEventListener("DOMContentLoaded", function () {
  var root = document.documentElement;

  // Light / dark switch
  var themeBtn = document.getElementById("theme-toggle");
  if (themeBtn) themeBtn.addEventListener("click", function () {
    var next = root.getAttribute("data-theme") === "dark" ? "light" : "dark";
    root.setAttribute("data-theme", next);
    try { localStorage.setItem("gcet-theme", next); } catch (e) {}
  });

  // Sidebar open / close on small screens
  var menuBtn = document.getElementById("menu-btn"), scrim = document.getElementById("scrim");
  function setNav(open) { document.body.classList.toggle("nav-open", open); if (menuBtn) menuBtn.setAttribute("aria-expanded", open); }
  if (menuBtn) menuBtn.addEventListener("click", function () { setNav(!document.body.classList.contains("nav-open")); });
  if (scrim) scrim.addEventListener("click", function () { setNav(false); });

  // Login page: show / hide password
  var showBtn = document.getElementById("show-pass"), pass = document.getElementById("pass");
  if (showBtn && pass) showBtn.addEventListener("click", function () {
    var reveal = pass.type === "password";
    pass.type = reveal ? "text" : "password";
    showBtn.textContent = reveal ? "Hide" : "Show";
  });
});
