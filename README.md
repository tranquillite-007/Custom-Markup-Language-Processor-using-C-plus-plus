# txt-to-html-convertor-in-cpp

### **Documentation**

---

#### **Purpose**  
This code processes custom tags and converts them into HTML elements. It supports headings, semantic HTML tags, multimedia elements, and more. Each tag is processed based on its `tagName`, `content`, and an optional `className`.

---

#### **Supported Tags and Output**

---

##### **1. Paragraph Tag: `$paragraph`**  
Generates a `<p>` tag. If a `className` is provided, it adds a class attribute.  

**Input:**  
`$paragraph(This is a paragraph)`  

**Output:**  
- With `className`: `<p class="className">This is a paragraph</p>`  
- Without `className`: `<p>This is a paragraph</p>`  

---

##### **2. Headings: `$heading1` to `$heading6`**  
Generates heading tags `<h1>` to `<h6>`. Includes `className` if specified.  

**Input:**  
`$heading1(This is a heading)`  

**Output:**  
- With `className`: `<h1 class="className">This is a heading</h1>`  
- Without `className`: `<h1>This is a heading</h1>`  

---

##### **3. Semantic HTML Tags**  
**Tags:** `$header_start`, `$header_end`, `$nav_start`, `$main_start`, `$article_start`, `$aside_start`, `$section_start`, `$footer_start` and their `_end` variants.  

**Output:**  
- Start Tag: `<header>`, `<nav>`, `<main>`, etc.  
  - With `className`: `<header class="className">`  
  - Without `className`: `<header>`  
- End Tag: `</header>`, `</nav>`, `</main>`, etc.  

---

##### **4. Div Tag: `$div_start` and `$div_end`**  
Generates `<div>` tags.  

**Input:**  
`$div_start`  

**Output:**  
- With `className`: `<div class="className">`  
- Without `className`: `<div>`  

**End Tag:**  
`$div_end` → `</div>`  

---

##### **5. Image Tag: `$image`**  
Generates an `<img>` tag with `src` and `alt` attributes.  

**Input:**  
`$image(image.jpg,An image description)`  

**Output:**  
- With `className`: `<img class="className" src="image.jpg" alt="An image description">`  
- Without `className`: `<img src="image.jpg" alt="An image description">`  

---

##### **6. Link Tag: `$link`**  
Generates an `<a>` tag with `href` and link text.  

**Input:**  
`$link(url.com,Click here)`  

**Output:**  
- With `className`: `<a class="className" href="url.com">Click here</a>`  
- Without `className`: `<a href="url.com">Click here</a>`  

---

##### **7. Audio Tag: `$audio`**  
Generates an `<audio>` tag with a `src` attribute.  

**Input:**  
`$audio(audio.mp3)`  

**Output:**  
- With `className`: `<audio class="className" controls><source src="audio.mp3" type="audio/mpeg"></audio>`  
- Without `className`: `<audio controls><source src="audio.mp3" type="audio/mpeg"></audio>`  

---

##### **8. Video Tag: `$video`**  
Generates a `<video>` tag with a `src` attribute.  

**Input:**  
`$video(video.mp4)`  

**Output:**  
- With `className`: `<video class="className" controls><source src="video.mp4" type="video/mp4"></video>`  
- Without `className`: `<video controls><source src="video.mp4" type="video/mp4"></video>`  

---

##### **9. Picture Tag: `$picture`**  
Generates a `<picture>` tag with responsive `<source>` and fallback `<img>`.  

**Input:**  
`$picture(image.webp)`  

**Output:**  
- With `className`: `<picture class="className"><source srcset="image.webp" type="image/webp"><img src="image.webp" alt="Responsive image"></picture>`  
- Without `className`: `<picture><source srcset="image.webp" type="image/webp"><img src="image.webp" alt="Responsive image"></picture>`  

---

##### **10. Embed Tag: `$embed`**  
Generates an `<embed>` tag for PDFs or similar files.  

**Input:**  
`$embed(file.pdf)`  

**Output:**  
- With `className`: `<embed class="className" src="file.pdf" type="application/pdf">`  
- Without `className`: `<embed src="file.pdf" type="application/pdf">`  

---

##### **11. Object Tag: `$object`**  
Generates an `<object>` tag for embedding files.  

**Input:**  
`$object(file.pdf)`  

**Output:**  
- With `className`: `<object class="className" data="file.pdf" type="application/pdf"></object>`  
- Without `className`: `<object data="file.pdf" type="application/pdf"></object>`  

---

##### **12. Iframe Tag: `$iframe`**  
Generates an `<iframe>` tag with a `src` attribute.  

**Input:**  
`$iframe(url.com)`  

**Output:**  
- With `className`: `<iframe class="className" src="url.com" frameborder="0" allowfullscreen></iframe>`  
- Without `className`: `<iframe src="url.com" frameborder="0" allowfullscreen></iframe>`  

---

##### **13. Canvas Tag: `$canvas`**  
Generates a `<canvas>` tag with a `width` attribute.  

**Input:**  
`$canvas(500)`  

**Output:**  
- With `className`: `<canvas class="className" width="500"></canvas>`  
- Without `className`: `<canvas width="500"></canvas>`  

---

##### **14. SVG Tag: `$svg`**  
Generates an `<svg>` tag with a `viewBox` attribute.  

**Input:**  
`$svg(0 0 100 100)`  

**Output:**  
- With `className`: `<svg class="className" xmlns="http://www.w3.org/2000/svg" viewBox="0 0 100 100"></svg>`  
- Without `className`: `<svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 100 100"></svg>`  

---

##### **15. Input Tag: `$input`**  
Generates an `<input>` tag with `type` and `placeholder` attributes.  

**Input:**  
`$input(text,Enter your name)`  

**Output:**  
- With `className`: `<input class="className" type="text" placeholder="Enter your name">`  
- Without `className`: `<input type="text" placeholder="Enter your name">`  

---

##### **16. Textarea Tag: `$textarea`**  
Generates a `<textarea>` tag with a `placeholder` attribute.  

**Input:**  
`$textarea(Enter your message)`  

**Output:**  
- With `className`: `<textarea class="className" placeholder="Enter your message"></textarea>`  
- Without `className`: `<textarea placeholder="Enter your message"></textarea>`  

---

##### **17. Label Tag: `$label`**  
Generates a `<label>` tag for form elements.  

**Input:**  
`$label(forInput,Name)`  

**Output:**  
- With `className`: `<label class="className" for="forInput">Name</label>`  
- Without `className`: `<label for="forInput">Name</label>`  

---

##### **18. Button Tag: `$button`**  
Generates a `<button>` tag with text content.  

**Input:**  
`$button(Submit)`  

**Output:**  
- With `className`: `<button class="className">Submit</button>`  
- Without `className`: `<button>Submit</button>`  
