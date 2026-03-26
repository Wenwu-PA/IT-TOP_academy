package com.example.todo_list.ui.components

import androidx.compose.foundation.layout.Row
import androidx.compose.foundation.layout.Spacer
import androidx.compose.foundation.layout.fillMaxWidth
import androidx.compose.foundation.layout.width
import androidx.compose.material3.Button
import androidx.compose.material3.Text
import androidx.compose.material3.TextField
import androidx.compose.runtime.Composable
import androidx.compose.ui.Modifier
import androidx.compose.ui.res.stringResource
import androidx.compose.ui.unit.dp
import com.example.todo_list.R

@Composable
fun TaskAdd(
    taskText: String,
    onTaskTextChange: (String) -> Unit,
    onAddTask: (String) -> Unit,
    modifier: Modifier = Modifier
) {
    Row(modifier = modifier.fillMaxWidth()) {
        TextField(
            value = taskText,
            onValueChange = onTaskTextChange,
            modifier = Modifier.weight(1f),
            placeholder = { Text(stringResource(R.string.placeholder_text)) }
        )

        Spacer(modifier = Modifier.width(8.dp))

        Button(
            onClick = {
                if (taskText.isNotBlank()) {
                    onAddTask(taskText)
                    onTaskTextChange("")
                }
            }
        ) {
            Text(stringResource(R.string.plus))
        }
    }
}