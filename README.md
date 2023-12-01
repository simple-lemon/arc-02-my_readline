# arc-02-my_readline
<div class="card-block">
<div class="row">
<div class="col tab-content">
<div class="tab-pane active show" id="subject" role="tabpanel">
<div class="row">
<div class="col-md-12 col-xl-12">
<div class="markdown-body">
<p class="text-muted m-b-15">
</p><h1>My Readline</h1>
<p>Remember to git add &amp;&amp; git commit &amp;&amp; git push each exercise!</p>
<p>We will execute your function with our test(s), please DO NOT PROVIDE ANY TEST(S) in your file</p>
<p>For each exercise, you will have to create a folder and in this folder, you will have additional files that contain your work. Folder names are provided at the beginning of each exercise under <code>submit directory</code> and specific file names for each exercise are also provided at the beginning of each exercise under <code>submit file(s)</code>.</p>
<hr>
<table>
<thead>
<tr>
<th>My Readline</th>
<th></th>
</tr>
</thead>
<tbody>
<tr>
<td>Submit directory</td>
<td>.</td>
</tr>
<tr>
<td>Submit file</td>
<td>my_readline.c</td>
</tr>
</tbody>
</table>
<h3>Description</h3>
<h2>NAME</h2>
<p><code>char *my_readline(int fd);</code></p>
<h2>Prolog</h2>
<p>If you already played with another higher-level programming language, you know how easy it is to read a line from a file. For example in Python, you can even iterate through the file like <strong>for line in file:</strong>.</p>
<p>Unfortunately for you, this project will bring you back in the 1970s (again) when no such super power was available.</p>
<p>Fortunately for you, you will discover the concept of global variables and gain a deeper understanding of how the heap and the stack interact with each other.</p>
<h2>Synopsis</h2>
<p>The function <code>my_readline</code> reads a line from the strean represented by <code>fd</code> and returns it into an allocated string (heap or stack ?). It stops when either the newline character is read or when the end-of-file is reached, whichever comes first. The newline character is not copied to the string.</p>
<p>On success, a pointer to the string is returned. On error, a <em>null</em> pointer is returned. If the end-of-file occurs before any characters have been read, the string remains unchanged.</p>
<p>Number of characters read will be set by the global variable READLINE_READ_SIZE
You are allowed to maximum two global variables (one for your "storage" and one for READLINE_READ_SIZE). Be ready, we will change the value of READLINE_READ_SIZE.</p>
<h2>Requirements</h2>
<ul>
<li>Your code must be compiled with the flags <strong>-Wall -Wextra -Werror</strong>.</li>
</ul>
<h2>Technical description</h2>
<p>In order to start reading another file you will also produce a function:
<code>void init_my_readline()</code> which will init (or reinitialize) your global variable.</p>
<p>In the case of reinitialize, you will, obviously, free allocated resources. :-)</p>
<h2>Hints</h2>
<ul>
<li>• Your function should work with any of streams, whether it be a file, standard input or a redirection...</li>
<li>• Your function should be able to be used in a loop to read an entire file (see example)</li>
<li>• Watch out for <strong>memory leaks</strong> !</li>
<li>• You can test your code against memory errors by compiling with the debugging flags <strong>-g3 -fsanitize=address</strong>
</li>
<li>• <strong>Static variables are strictly FORBIDDEN</strong>
</li>
</ul>
<h2>Authorized function(s)</h2>
<ul>
<li>• malloc(3)</li>
<li>• free</li>
<li>• read</li>
<li>• open</li>
<li>• close</li>
</ul>
<h2>Unauthorized function(s)</h2>
<ul>
<li>lseek</li>
<li>fread</li>
<li>fopen</li>
<li>Any other functions or system calls</li>
</ul>
<ul>
<li>Multiline macros are forbidden</li>
<li>Include another .c is forbidden</li>
<li>Macros with logic (while/if/variables/...) are forbidden</li>
</ul>
<p><strong>Example 00 (In C)</strong></p>
<pre class=" language-c"><code class=" language-c"><span class="token keyword">int</span> READLINE_READ_SIZE <span class="token operator">=</span> <span class="token number">512</span><span class="token punctuation">;</span>

<span class="token keyword">int</span> <span class="token function">main</span><span class="token punctuation">(</span><span class="token keyword">int</span> ac<span class="token punctuation">,</span> <span class="token keyword">char</span> <span class="token operator">*</span><span class="token operator">*</span>av<span class="token punctuation">)</span>
<span class="token punctuation">{</span>
  <span class="token keyword">char</span> <span class="token operator">*</span>str <span class="token operator">=</span> <span class="token constant">NULL</span><span class="token punctuation">;</span>

  <span class="token keyword">int</span> fd <span class="token operator">=</span> <span class="token function">open</span><span class="token punctuation">(</span><span class="token string">"./file.txt"</span><span class="token punctuation">,</span> O_RDONLY<span class="token punctuation">)</span><span class="token punctuation">;</span>
  <span class="token keyword">while</span> <span class="token punctuation">(</span><span class="token punctuation">(</span>str <span class="token operator">=</span> <span class="token function">my_readline</span><span class="token punctuation">(</span>fd<span class="token punctuation">)</span><span class="token punctuation">)</span> <span class="token operator">!=</span> <span class="token constant">NULL</span><span class="token punctuation">)</span>
  <span class="token punctuation">{</span>
      <span class="token function">printf</span><span class="token punctuation">(</span><span class="token string">"%s\n"</span><span class="token punctuation">,</span> str<span class="token punctuation">)</span><span class="token punctuation">;</span>
      <span class="token function">free</span><span class="token punctuation">(</span>str<span class="token punctuation">)</span><span class="token punctuation">;</span>
  <span class="token punctuation">}</span>
  <span class="token function">close</span><span class="token punctuation">(</span>fd<span class="token punctuation">)</span><span class="token punctuation">;</span>
  <span class="token comment">//</span>
  <span class="token comment">//  Yes it's also working with stdin :-)</span>
  <span class="token comment">//  printf("%s", my_readline(0));</span>
  <span class="token comment">//</span>

  <span class="token keyword">return</span> <span class="token number">0</span><span class="token punctuation">;</span>
<span class="token punctuation">}</span>
</code></pre>

<p></p>
</div>

</div>
</div>
</div>
<div class="tab-pane" id="resources" role="tabpanel">
</div>
</div>
</div>
</div>
