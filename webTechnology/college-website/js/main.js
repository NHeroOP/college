/* main.js - JavaScript for the public website pages (theme, menu, slider, pop-up, filters, form message) */

// 1. Theme: apply saved / system theme immediately (script is loaded in <head> to avoid a flash)
var saved = null;
try { saved = localStorage.getItem("gcet-theme"); } catch (e) {}
document.documentElement.setAttribute("data-theme",
  saved || (window.matchMedia("(prefers-color-scheme: dark)").matches ? "dark" : "light"));

document.addEventListener("DOMContentLoaded", function () {
  var root = document.documentElement;
  var sun = '<img src="assets/icons/sun.svg" alt="">';
  var moon = '<img src="assets/icons/moon.svg" alt="">';
  var toggle = document.getElementById("theme-toggle");

  function paintToggle() {
    var dark = root.getAttribute("data-theme") === "dark";
    toggle.innerHTML = dark ? sun : moon;
    toggle.setAttribute("aria-label", dark ? "Switch to light mode" : "Switch to dark mode");
  }
  paintToggle();
  toggle.addEventListener("click", function () {
    var next = root.getAttribute("data-theme") === "dark" ? "light" : "dark";
    root.setAttribute("data-theme", next);
    try { localStorage.setItem("gcet-theme", next); } catch (e) {}
    paintToggle();
  });

  // 2. Mobile menu
  var menuBtn = document.getElementById("menu-btn"), list = document.getElementById("nav-list");
  menuBtn.addEventListener("click", function () {
    var open = list.classList.toggle("open");
    menuBtn.setAttribute("aria-expanded", open);
  });

  // 3. Home page hero slider: crossfade + ONE progress line that fills, then resets for the next photo
  var slides = document.querySelectorAll(".hero-slides img");
  if (slides.length) {
    var bar = document.querySelector(".hero-progress"), n = 0, timer;
    var TIME = 6000;                                   // keep equal to --slide-time (6s) in style.css
    var still = window.matchMedia("(prefers-reduced-motion: reduce)").matches;
    function show(i) {
      n = (i + slides.length) % slides.length;
      slides.forEach(function (s, k) { s.classList.toggle("active", k === n); });
      bar.classList.remove("run");                     // snap the line back to empty
      void bar.offsetWidth;                            // restart the CSS animation
      clearTimeout(timer);
      if (!still) { bar.classList.add("run"); timer = setTimeout(function () { show(n + 1); }, TIME); }
    }
    document.getElementById("prev").onclick = function () { show(n - 1); };
    document.getElementById("next").onclick = function () { show(n + 1); };
    show(0);
  }

  // 4. Faculty "View Details" pop-up (reads data-* attributes from the card button)
  var dlg = document.getElementById("faculty-dialog");
  if (dlg) {
    document.querySelectorAll(".view-details").forEach(function (btn) {
      btn.addEventListener("click", function () {
        var d = btn.dataset;
        document.getElementById("fd-name").textContent = d.name;
        document.getElementById("fd-info").innerHTML =
          "<dt>Designation</dt><dd>" + d.role + "</dd><dt>Department</dt><dd>Computer Science</dd>" +
          "<dt>Qualification</dt><dd>" + d.qual + "</dd><dt>Email</dt><dd>" + d.email + "</dd>";
        dlg.showModal();
      });
    });
    document.getElementById("fd-close").onclick = function () { dlg.close(); };
    dlg.addEventListener("click", function (e) { if (e.target === dlg) dlg.close(); });
  }

  // 5. Students page: filter notices by category
  var filters = document.querySelectorAll(".filter");
  filters.forEach(function (btn) {
    btn.addEventListener("click", function () {
      filters.forEach(function (b) { b.setAttribute("aria-pressed", b === btn); });
      document.querySelectorAll(".notice").forEach(function (item) {
        item.hidden = btn.dataset.tag !== "All" && item.dataset.tag !== btn.dataset.tag;
      });
    });
  });

  // 6. Admission form: show a confirmation instead of leaving the page
  var form = document.getElementById("admission-form");
  if (form) {
    var ok = document.getElementById("form-success");
    document.getElementById("dob").max = new Date().toISOString().split("T")[0];
    form.addEventListener("submit", function (e) {
      e.preventDefault();                       // runs only when browser validation has passed
      document.getElementById("ok-name").textContent = form.elements["name"].value;
      document.getElementById("ok-course").textContent = form.elements["course"].value;
      form.hidden = true; ok.hidden = false; ok.scrollIntoView({ behavior: "smooth" });
    });
    document.getElementById("again").onclick = function () { form.reset(); form.hidden = false; ok.hidden = true; };
  }
});
