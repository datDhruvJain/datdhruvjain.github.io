# Some recurring searches I make on markdown
[Referencing headers in markdown](#to-generate-the-indexes-or-links-to-headers-in-a-markdown-file)
[To create dropdowns in markdown](#to-create-dropdowns-in-markdown)

## To generate the indexes or links to headers in a markdown file

markdown implicitlty creates ids for headers in a file. So you can create links to them by doing #name-of-header, where `-` replaces any spaces


eg: `[Referencing headers in markdown](#To-generate-the-indexes-or-links-to-headers-in-a-markdown-file)`

#### check and uncheck symbols in markdown
`&check;` and `&cross;` from those symbols

## To create dropdowns in markdown

```
<details markdown=1>
<summary>Want to ruin the surprise?</summary>
<br>
Well, you asked for it!
</details>
```

<details markdown=1>
<summary>How do I dropdown?</summary>
<br>
This is how you dropdown.
</details>

and 

<details markdown=1 open>
<summary>Want to ruin the surprise?</summary>
<br>
Well, you asked for it!
</details>