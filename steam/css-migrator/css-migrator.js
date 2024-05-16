const axios = require('axios');
const fs = require('fs').promises;
const path = require('path');

async function run() {
  const [mappingUrl, sourcePath, outputPath, compact] = process.argv.slice(2);

  if (!mappingUrl || !sourcePath || !outputPath) {
    console.error(
      'Please provide at least three arguments: mapping_url, source_path, output_path, compact'
    );
    return;
  }

  try {
    const mappingData = await fetchMappingData(mappingUrl);
    const files = await fs.readdir(sourcePath);

    for (const fileName of files) {
      if (fileName.endsWith('.css')) {
        await processFile(
          mappingData,
          sourcePath,
          outputPath,
          compact,
          fileName
        );
      }
    }
  } catch (error) {
    console.error(`Error: ${error}`);
  }
}

async function fetchMappingData(mappingUrl) {
  try {
    const response = await axios.get(mappingUrl);
    return response.data;
  } catch (error) {
    throw new Error(`Error fetching mapping data: ${error}`);
  }
}

async function processFile(
  mappingData,
  sourcePath,
  outputPath,
  compact,
  fileName
) {
  const sourceFile = path.join(sourcePath, fileName);
  const outputFile = path.join(outputPath, fileName);

  try {
    let content = await fs.readFile(sourceFile, 'utf8');

    for (const [_, children] of Object.entries(mappingData)) {
      const replacement = `.${children[children.length - 1]}`;

      for (let i = 0; i < children.length - 1; i++) {
        const child = children[i];

        if (child) {
          const pattern = `(?:\\[class(?:\\*|\\^)?=(?:'|")|\\.)${escapeRegex(
            child
          )}\\b(?:(?:'|")\\])?`;

          content = content.replace(new RegExp(pattern, 'g'), replacement);
        }
      }
    }

    if (compact) {
      content = content.replace(/\/\*[\s\S]*?\*\//gm, '').replace(/\n+/g, '\n');
    }

    await fs.writeFile(outputFile, content, 'utf8');
    console.log(`Replaced CSS selectors [${sourceFile} > ${outputFile}]`);
  } catch (error) {
    console.error(`Error processing file [${sourceFile}]: ${error}`);
  }
}

function escapeRegex(string) {
  return string.replace(/[/\-\\^$*+?.()|[\]{}]/g, '\\$&');
}

run();
